import os
import mysql.connector

class DBService:
    def __init__(self):
        self.host = os.getenv("DB_HOST")
        self.user = os.getenv("DB_USER")
        self.password = os.getenv("DB_PASSWORD")
        self.default_db = os.getenv("DB_NAME")

    def _connect(self, db_name=None):
        return mysql.connector.connect(
            host=self.host,
            user=self.user,
            password=self.password,
            database=db_name or self.default_db
        )

    def get_schema(self, db_name=None) -> dict:
        # return { "table": ["col1","col2",...] }
        pass

    def validate_sql(self, sql: str):
        pass

    def run(self, sql: str, db_name=None):
        pass

db = DBService()