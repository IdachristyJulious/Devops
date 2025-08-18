pipeline {
    agent any

    environment {
        DEPLOY_DIR = '/var/www/pythonapp'         // Local deploy path
        VENV_DIR = 'venv'                         // Virtual environment name
        ENTRY_POINT = 'app/main.py'               // Your main Python file
        LOG_FILE = 'app.log'                      // Log file for app output
    }

    stages {
        stage('Clone Repository') {
            steps {
                git url: 'https://github.com/your-username/your-repo.git'
            }
        }

        stage('Setup Python Environment') {
            steps {
                echo 'Setting up virtual environment...'
                sh """
                    python3 -m venv $VENV_DIR
                    source $VENV_DIR/bin/activate
                    pip install --upgrade pip
                    pip install -r requirements.txt
                """
            }
        }

        stage('Run Tests') {
            steps {
                echo 'Running unit tests...'
                sh """
                    source $VENV_DIR/bin/activate
                    python -m unittest discover tests
                """
            }
        }

        stage('Deploy Application') {
            steps {
                echo 'Deploying application locally...'
                sh """
                    mkdir -p $DEPLOY_DIR
                    cp -r * $DEPLOY_DIR/
                    pkill -f $ENTRY_POINT || true
                    nohup python3 $DEPLOY_DIR/$ENTRY_POINT > $DEPLOY_DIR/$LOG_FILE 2>&1 &
                """
            }
        }
    }

    post {
        success {
            echo '✅ Python application deployed successfully.'
        }
        failure {
            echo '❌ Deployment failed. Check console logs.'
        }
    }
}
