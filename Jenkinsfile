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

        stage('Setup Submodules') {
            parallel {
                stage('CMSIS + HAL') {
                    steps {
                        sh 'chmod +x scripts/stm32f4_drivers_add_or_update_subs.sh'
                        sh './scripts/stm32f4_drivers_add_or_update_subs.sh'
                    }
                }
                stage('Unity') {
                    steps {
                        sh 'chmod +x scripts/unity_add_or_update_sub.sh'
                        sh './scripts/unity_add_or_update_sub.sh'
                    }
                }
            }
        }

        stage('Build & Flash') {
            steps {
                echo "=== Building firmware and flashing board ==="
                sh 'make test'
            }
        }

        stage('Verify USB access') {
            steps {
                sh 'ls -l /dev/ttyUSB0'
                sh 'groups'
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

        stage('Kill OpenOCD detached daemon') {
            steps {
                echo "=== Killing OpenOCD detached daemon ==="
                sh 'make kill_detached_openocd'
            }
        }
    }

    post {
        success {
            echo "✅ Build & Tests succeeded!"
        }
        failure {
            script {
                if (fileExists('stm32f4_prj/tests/run_test_commands.log')) {
                    echo "=== Unit Test Log ==="
                    sh 'cat stm32f4_prj/tests/run_test_commands.log'
                }
            }
            echo "❌ Build or Tests failed!"
        }
        always {
            archiveArtifacts artifacts: 'build/**/*.elf, build/**/*.bin, stm32f4_prj/tests/*.log', fingerprint: true
        }
    }
}
