pipeline {
    agent any

    tools {
        python 'Python3'  // Make sure Python is installed and configured in Jenkins Global Tool Configuration
    }

    environment {
        VENV_DIR = 'venv'
    }

    stages {

        stage('Clone Repository') {
            steps {
                git credentialsId: 'your-github-credentials-id', url: 'https://github.com/IdachristyJulious/Devops.git'
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
                    REM Add deployment commands here
                """
            }
        }
    }

    post {
        success {
            echo '✅ Build and Deployment completed successfully.'
        }
        failure {
            echo '❌ Deployment failed. Check console logs.'
        }
    }
}

