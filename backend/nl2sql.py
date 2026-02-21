class NL2SQL:
    def __init__(self):
        self.model = None

    def load_model(self, path: str):
        pass

    def to_sql(self, text: str, schema: dict) -> str:
        # Placeholder: friend replaces this with ML model
        raise NotImplementedError

nl2sql = NL2SQL()