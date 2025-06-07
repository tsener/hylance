import os
import importlib.util
import pytest
from io import BytesIO
from wsgiref.util import setup_testing_defaults

# Skip tests if bottle is not available
if importlib.util.find_spec("bottle") is None:
    pytest.skip("bottle not installed", allow_module_level=True)

spec = importlib.util.spec_from_file_location(
    "service", os.path.join(os.path.dirname(__file__), "..", "cmd", "service", "main.py")
)
service = importlib.util.module_from_spec(spec)
spec.loader.exec_module(service)
app = service.app


def call_get(path):
    env = {}
    setup_testing_defaults(env)
    env["PATH_INFO"] = path
    env["REQUEST_METHOD"] = "GET"
    body = BytesIO()
    status = {}

    def start_response(s, h):
        status["status"] = s

    for chunk in app(env, start_response):
        body.write(chunk)
    return status["status"], body.getvalue().decode()


def write_config(path):
    path.write_text(
        "hitch:\n  frontend: \"[0.0.0.0]:443\"\n" \
        "balance:\n  listen: \"0.0.0.0 8080\"\n  backends:\n    - \"a:1\"\n    - \"b:2\"\n"
    )


def test_config_endpoints(tmp_path):
    cfg = tmp_path / "config.yaml"
    write_config(cfg)
    os.environ["HYLANCE_CONFIG"] = str(cfg)

    status, body = call_get("/config/hitch")
    assert status.startswith("200")
    assert "[0.0.0.0]:443" in body

    status, body = call_get("/config/balance")
    assert status.startswith("200")
    assert "0.0.0.0 8080" in body

