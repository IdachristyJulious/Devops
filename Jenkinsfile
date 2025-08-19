pipeline {
    agent any

    environment {
        VENV_DIR = 'venv'
    }

    stages {

        stage('Clone Repository') {
            steps {
                git credentialsId: c6628c06-6ac9-4dc7-863c-32c39834d887", url: 'https://github.com/IdachristyJulious/Devops.git'
            }
        }

        stage('Setup Python Environment') {
            steps {
                bat """
                    python -m venv %VENV_DIR%
                    call %VENV_DIR%\\Scripts\\activate
                    pip install --upgrade pip
                    pip install -r requirements.txt
                """
            }
        }

        stage('Run Tests') {
            steps {
                bat """
                    call %VENV_DIR%\\Scripts\\activate
                    pytest tests/
                """
            }
        }

        stage('Deploy Application') {
            steps {
                bat """
                    call %VENV_DIR%\\Scripts\\activate
                    echo Deploying your Python app...
                    REM Add deployment steps here (e.g., copying files or running scripts)
                """
            }
        }
    }

    post {
        success {
            echo '✅ Build and Deployment completed successfully.'
        }
        failure {
            echo '❌ Deployment failed. Check logs.'
        }
    }
}
