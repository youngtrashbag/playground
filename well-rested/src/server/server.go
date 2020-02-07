package server

import (
	"log"
	"net/http"
)

//codacy, again, says this needs comment, or it should not be exported(capital letter means export(public))
type Server struct{ }

//serve function
func (s *Server) ServeHTTP(res http.ResponseWriter, req *http.Request) {
	res.WriteHeader(http.StatusOK)
	res.Header().Set("Content-Type", "application/json")

	log.Println(composeMessage(req))

	message := `{"message": "` + composeMessage(req) + `"}`
	res.Write([]byte(message))
}

//compose a message
func composeMessage(req *http.Request) string {
	return req.Method + ` called to ` + req.RequestURI
}

//get request
func Get(res http.ResponseWriter, req *http.Request) {
	log.Println(composeMessage(req))
	res.Header().Set("Content-Type", "application/json")
	res.WriteHeader(http.StatusOK)
	res.Write([]byte(`{"message": "get called"}`))
}

//post request
func Post(res http.ResponseWriter, req *http.Request) {
	log.Println(composeMessage(req))
	res.Header().Set("Content-Type", "application/json")
	res.WriteHeader(http.StatusCreated)
	res.Write([]byte(`{"message": "post called"}`))
}

//put request
func Put(res http.ResponseWriter, req *http.Request) {
	log.Println(composeMessage(req))
	res.Header().Set("Content-Type", "application/json")
	res.WriteHeader(http.StatusAccepted)
	res.Write([]byte(`{"message": "put called"}`))
}

//delete request
func Delete(res http.ResponseWriter, req *http.Request) {
	log.Println(composeMessage(req))
	res.Header().Set("Content-Type", "application/json")
	res.WriteHeader(http.StatusOK)
	res.Write([]byte(`{"message": "delete called"}`))
}

//gets executed, when request does not match any of the above
func NotFound(res http.ResponseWriter, req *http.Request) {
	log.Println(composeMessage(req))
	res.Header().Set("Content-Type", "application/json")
	res.WriteHeader(http.StatusNotFound)
	res.Write([]byte(`{"message": "not found"}`))
}

