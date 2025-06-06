import os
import yaml
from bottle import Bottle, response, run

CONFIG_PATH = os.environ.get('HYLANCE_CONFIG', '/etc/hylance/hylance.yaml')

app = Bottle()

def load_config():
    with open(CONFIG_PATH) as f:
        return yaml.safe_load(f) or {}

@app.get('/config/hitch')
def hitch_config():
    cfg = load_config().get('hitch', {})
    response.content_type = 'application/json'
    return cfg

@app.get('/config/balance')
def balance_config():
    cfg = load_config().get('balance', {})
    response.content_type = 'application/json'
    return cfg

if __name__ == '__main__':
    run(app, host='0.0.0.0', port=8080)
