from fastapi import FastAPI
from pydantic import BaseModel
from db_service import db
from nl2sql import nl2sql

app = FastAPI()

class NLQRequest(BaseModel):
    tex: str
    db: str | None = None

class SQLRequest(BaseModel):
    sql: str
    db: str | None = None   

@app.get("/")
def health():
    return {"status": "ok"}

@app.post("/nlq") 
def n1_query(req: NLQRequest):
    schema = db.get_schema(db_name=req.db)
    sql = nl2sql.to_sql(req.text, schema)
    db.validate_sql(sql)
    rows = db.run(sql, db_name=req.db)
    return {"sql": sql, "rows": rows}    

@app.post("/sql")
def raw_sql(req: SQLRequest):
    db.validate_sql(req.sql)
    rows = db.run(req.sql, db_name=req.db)
    return {"sql": req.sql, "rows": rows}