pipeline {
    agent any

    environment {
        VENV_DIR = 'venv'  // Virtual environment folder
    }

    stages {

        stage('Clone Repository') {
            steps {
                git branch: 'main',  // Change this to your actual branch (main/master)
                    credentialsId: 'c6628c06-6ac9-4dc7-863c-32c39834d887',
                    url: 'https://github.com/IdachristyJulious/Devops.git'
            }
        }

        stage('Setup Python Environment') {
            steps {
                bat """
                    python -m venv %VENV_DIR%
                    call %VENV_DIR%\\Scripts\\activate
                    pip install --upgrade pip
                    pip install -r requirement.txt
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
                    REM You can copy files or run scripts here
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

