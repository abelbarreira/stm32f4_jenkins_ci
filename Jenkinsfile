pipeline {
    agent any

    environment {
        PATH = "/usr/local/bin:/usr/bin:/bin:${env.PATH}"
    }

    stages {
        stage('Checkout') {
            steps {
                checkout([
                    $class: 'GitSCM',
                    branches: [[name: '*/main']],
                    userRemoteConfigs: [[url: 'https://github.com/abelbarreira/stm32f4_jenkins_ci.git']]
                ])
            }
        }

        stage('Setup Submodules (CMSIS + HAL)') {
            steps {
                echo "=== Setting up Git submodules (CMSIS + HAL) ==="
                sh 'chmod +x scripts/stm32f4_drivers_add_or_update_subs.sh'
                sh './scripts/stm32f4_drivers_add_or_update_subs.sh'
            }
        }

        stage('Setup Unity Submodule') {
            steps {
                echo "=== Setting up Unity test framework submodule ==="
                sh 'chmod +x scripts/unity_add_or_update_sub.sh'
                sh './scripts/unity_add_or_update_sub.sh'
            }
        }

        stage('Build & Flash') {
            steps {
                echo "=== Building firmware and flashing board ==="
                sh 'make test'
            }
        }

        stage('Run Tests') {
            steps {
                echo "=== Running unit tests on hardware ==="
                sh './scripts/unit_test_run.sh'
                script {
                    if (!fileExists('stm32f4_prj/tests/run_test_commands.log')) {
                        error "❌ Unit test log not found!"
                    }
                }
            }
        }
    }

    post {
        success {
            echo "✅ Build & Tests succeeded!"
        }
        failure {
            echo "❌ Build or Tests failed!"
        }
        always {
            archiveArtifacts artifacts: 'build/**/*.elf, build/**/*.bin, stm32f4_prj/tests/*.log', fingerprint: true
        }
    }
}
