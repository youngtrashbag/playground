package pet

import (
	"net/http"
)

//comment becuase codacy
type Pet struct {
	ID   int `json:"id"`
	Name string `json:"name"`
	Age  int `json:"age"`
}

//get
func Get(res http.ResponseWriter, req *http.Request) {
	res.Header().Set("Content-Type", "application/json")
	res.WriteHeader(http.StatusOK)
	res.Write([]byte(`{"message": "get called"}`))
}

//post
func Post(res http.ResponseWriter, req *http.Request) {
	res.Header().Set("Content-Type", "application/json")
	res.WriteHeader(http.StatusCreated)
	res.Write([]byte(`{"message": "post called"}`))
}

//put
func Put(res http.ResponseWriter, req *http.Request) {
	res.Header().Set("Content-Type", "application/json")
	res.WriteHeader(http.StatusAccepted)
	res.Write([]byte(`{"message": "put called"}`))
}

//delete
func Delete(res http.ResponseWriter, req *http.Request) {
	res.Header().Set("Content-Type", "application/json")
	res.WriteHeader(http.StatusOK)
	res.Write([]byte(`{"message": "delete called"}`))
}

//not found -> any other http request than the ones listed as functions above
func NotFound(res http.ResponseWriter, req *http.Request) {
	res.Header().Set("Content-Type", "application/json")
	res.WriteHeader(http.StatusNotFound)
	res.Write([]byte(`{"message": "not found"}`))
}

