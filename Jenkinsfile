pipeline {
    agent any

    environment {
        PATH = "/usr/local/bin:/usr/bin:/bin:${env.PATH}"
    }

    stages {
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
