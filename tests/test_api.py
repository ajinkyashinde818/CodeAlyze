import sys
import tempfile
import unittest
from pathlib import Path
from unittest.mock import patch

ROOT = Path(__file__).resolve().parents[1]
BACKEND = ROOT / "backend"
sys.path.insert(0, str(BACKEND))

import predictor
from app import create_app


PYTHON_SAMPLE = "def add(a, b):\n    return a + b\n"


class ApiTestCase(unittest.TestCase):
    @classmethod
    def setUpClass(cls):
        cls.app = create_app()
        cls.app.config.update(TESTING=True, MAX_CODE_CHARS=100)
        cls.client = cls.app.test_client()

    def test_ready_endpoint_reports_model_status(self):
        response = self.client.get("/api/ready")
        self.assertIn(response.status_code, {200, 503})
        payload = response.get_json()
        self.assertIn("model", payload)

    def test_analyze_valid_input(self):
        with patch("routes.record_analysis"):
            response = self.client.post(
                "/api/analyze",
                json={"code": PYTHON_SAMPLE, "language": "Python"},
            )
        self.assertEqual(response.status_code, 200)
        payload = response.get_json()
        self.assertIn(payload["prediction"], {"AI Generated", "Human Written"})
        self.assertEqual(payload["language"], "Python")
        self.assertIn("model_version", payload)
        self.assertIn("confidence_method", payload)

    def test_analyze_empty_input(self):
        response = self.client.post("/api/analyze", json={"code": "   ", "language": "Python"})
        self.assertEqual(response.status_code, 400)

    def test_analyze_invalid_language(self):
        response = self.client.post("/api/analyze", json={"code": PYTHON_SAMPLE, "language": "Ruby"})
        self.assertEqual(response.status_code, 400)

    def test_analyze_oversized_input(self):
        response = self.client.post("/api/analyze", json={"code": "x" * 101, "language": "Python"})
        self.assertEqual(response.status_code, 400)

    def test_analyze_missing_code_field(self):
        response = self.client.post("/api/analyze", json={"language": "Python"})
        self.assertEqual(response.status_code, 400)

    def test_analyze_unicode_input_is_accepted(self):
        with patch("routes.record_analysis"):
            response = self.client.post(
                "/api/analyze",
                json={
                    "code": "# comentario com acentuacao\ndef soma(a, b):\n    return a + b\n",
                    "language": "Python",
                },
            )
        self.assertEqual(response.status_code, 200)

    def test_model_info_endpoint_reports_verified_status(self):
        response = self.client.get("/api/model-info")
        self.assertEqual(response.status_code, 200)
        payload = response.get_json()
        self.assertIn("model_version", payload)
        self.assertIn("dataset", payload)
        self.assertIn("evaluation", payload)
        self.assertIn("known_limitations", payload)
        # Metrics must never be invented when no evaluation artifact exists.
        self.assertNotIn("accuracy", payload)
        self.assertNotIn("confusion_matrix", payload)

    def test_dataset_audit_endpoint_never_invents_counts(self):
        response = self.client.get("/api/dataset-audit")
        self.assertEqual(response.status_code, 200)
        payload = response.get_json()
        self.assertIn("available", payload)
        self.assertIn("status", payload)
        if not payload["available"]:
            self.assertNotIn("total_files", payload)

    def test_admin_stats_endpoint_returns_usage_counts(self):
        response = self.client.get("/api/admin/stats")
        self.assertEqual(response.status_code, 200)
        payload = response.get_json()
        for key in ("total_analyses", "ai_count", "human_count", "language_distribution"):
            self.assertIn(key, payload)

    def test_admin_stats_export_csv_and_json(self):
        csv_response = self.client.get("/api/admin/stats/export?format=csv")
        self.assertEqual(csv_response.status_code, 200)
        self.assertIn("text/csv", csv_response.content_type)

        json_response = self.client.get("/api/admin/stats/export?format=json")
        self.assertEqual(json_response.status_code, 200)
        self.assertIsInstance(json_response.get_json(), list)

    def test_index_page_is_served(self):
        response = self.client.get("/")
        self.assertEqual(response.status_code, 200)
        self.assertIn(b"CodeAlyze", response.data)

    def test_index_page_has_no_dashboard_link(self):
        # The Dashboard nav item was removed because it pointed to a page that
        # is not part of this frontend. Assert the broken link stays gone.
        response = self.client.get("/")
        self.assertNotIn(b'href="/admin"', response.data)
        for section_id in (b'id="analyzer"', b'id="how-it-works"', b'id="model"', b'id="tech"'):
            self.assertIn(section_id, response.data)

    def test_missing_model_returns_503(self):
        original_path = predictor.MODEL_PATH
        predictor.reset_model_cache()
        with tempfile.TemporaryDirectory() as tmp:
            predictor.MODEL_PATH = str(Path(tmp) / "missing.pkl")
            response = self.client.post(
                "/api/analyze",
                json={"code": PYTHON_SAMPLE, "language": "Python"},
            )
        predictor.MODEL_PATH = original_path
        predictor.reset_model_cache()
        self.assertEqual(response.status_code, 503)
        self.assertEqual(response.get_json()["error"], "Model unavailable")


class PredictorStatusTestCase(unittest.TestCase):
    """The status helpers must stay honest about missing evidence."""

    def test_evaluation_status_is_honest_without_artifact(self):
        with tempfile.TemporaryDirectory() as tmp:
            original = predictor.EVALUATION_METRICS_PATH
            predictor.EVALUATION_METRICS_PATH = str(Path(tmp) / "absent.json")
            try:
                status = predictor.evaluation_status()
            finally:
                predictor.EVALUATION_METRICS_PATH = original
        self.assertFalse(status["available"])
        self.assertIn("pending", status["status"].lower())
        self.assertNotIn("accuracy", status)

    def test_dataset_status_is_honest_without_artifact(self):
        with tempfile.TemporaryDirectory() as tmp:
            original = predictor.DATASET_AUDIT_PATH
            predictor.DATASET_AUDIT_PATH = str(Path(tmp) / "absent.json")
            try:
                status = predictor.dataset_status()
            finally:
                predictor.DATASET_AUDIT_PATH = original
        self.assertFalse(status["available"])
        self.assertNotIn("total_files", status)

    def test_dataset_status_reports_real_audit_counts(self):
        with tempfile.TemporaryDirectory() as tmp:
            audit_path = Path(tmp) / "audit.json"
            audit_path.write_text(
                '{"available": true, "dataset_root": "dataset", "total_files": 12,'
                ' "counts_by_label": {"ai": 6, "human": 6}, "empty_files": 0}',
                encoding="utf-8",
            )
            original = predictor.DATASET_AUDIT_PATH
            predictor.DATASET_AUDIT_PATH = str(audit_path)
            try:
                status = predictor.dataset_status()
            finally:
                predictor.DATASET_AUDIT_PATH = original
        self.assertTrue(status["available"])
        self.assertEqual(status["total_files"], 12)
        self.assertEqual(status["counts_by_label"]["ai"], 6)

    def test_evaluation_status_reports_real_metrics(self):
        with tempfile.TemporaryDirectory() as tmp:
            metrics_path = Path(tmp) / "metrics.json"
            metrics_path.write_text(
                '{"samples": 40, "accuracy": 0.875,'
                ' "classification_report": {"macro avg": {"f1-score": 0.86}},'
                ' "confusion_matrix": [[10, 2], [3, 25]]}',
                encoding="utf-8",
            )
            original = predictor.EVALUATION_METRICS_PATH
            predictor.EVALUATION_METRICS_PATH = str(metrics_path)
            try:
                status = predictor.evaluation_status()
            finally:
                predictor.EVALUATION_METRICS_PATH = original
        self.assertTrue(status["available"])
        self.assertEqual(status["samples"], 40)
        self.assertAlmostEqual(status["accuracy"], 0.875)

    def test_read_json_tolerates_corrupt_file(self):
        with tempfile.TemporaryDirectory() as tmp:
            bad_path = Path(tmp) / "bad.json"
            bad_path.write_text("not json at all", encoding="utf-8")
            self.assertIsNone(predictor._read_json(str(bad_path)))

    def test_score_is_labelled_uncalibrated(self):
        info = predictor.model_info()
        if info.get("available"):
            self.assertEqual(
                info.get("score_method"),
                "sigmoid_absolute_linear_svm_margin_not_calibrated",
            )


if __name__ == "__main__":
    unittest.main()
