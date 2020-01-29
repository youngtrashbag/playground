package pet

import (
	"net/http"
)

type Pet struct {
	Id   int `json:"id"`
	Name string `json:"name"`
	Age  int `json:"age"`
}

func Get(res http.ResponseWriter, req *http.Request) {
	res.Header().Set("Content-Type", "application/json")
	res.WriteHeader(http.StatusOK)
	res.Write([]byte(`{"message": "get called"}`))
}

func Post(res http.ResponseWriter, req *http.Request) {
	res.Header().Set("Content-Type", "application/json")
	res.WriteHeader(http.StatusCreated)
	res.Write([]byte(`{"message": "post called"}`))
}

func Put(res http.ResponseWriter, req *http.Request) {
	res.Header().Set("Content-Type", "application/json")
	res.WriteHeader(http.StatusAccepted)
	res.Write([]byte(`{"message": "put called"}`))
}

func Delete(res http.ResponseWriter, req *http.Request) {
	res.Header().Set("Content-Type", "application/json")
	res.WriteHeader(http.StatusOK)
	res.Write([]byte(`{"message": "delete called"}`))
}

func NotFound(res http.ResponseWriter, req *http.Request) {
	res.Header().Set("Content-Type", "application/json")
	res.WriteHeader(http.StatusNotFound)
	res.Write([]byte(`{"message": "not found"}`))
}
