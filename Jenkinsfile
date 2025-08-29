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
            archiveArtifacts artifacts: 'build/**/*.elf, build/**/*.bin', fingerprint: true
        }
    }
}
