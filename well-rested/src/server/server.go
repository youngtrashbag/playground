package server

import (
	"log"
	"net/http"
)

type Server struct{ }

func (s *Server) ServeHTTP(res http.ResponseWriter, req *http.Request) {
	res.WriteHeader(http.StatusOK)
	res.Header().Set("Content-Type", "application/json")

	log.Println(composeMessage(req))

	message := `{"message": "` + composeMessage(req) + `"}`
	res.Write([]byte(message))
}

func composeMessage(req *http.Request) string {
	return req.Method + ` called to ` + req.RequestURI
}

func Get(res http.ResponseWriter, req *http.Request) {
	log.Println(composeMessage(req))
	res.Header().Set("Content-Type", "application/json")
	res.WriteHeader(http.StatusOK)
	res.Write([]byte(`{"message": "get called"}`))
}

func Post(res http.ResponseWriter, req *http.Request) {
	log.Println(composeMessage(req))
	res.Header().Set("Content-Type", "application/json")
	res.WriteHeader(http.StatusCreated)
	res.Write([]byte(`{"message": "post called"}`))
}

func Put(res http.ResponseWriter, req *http.Request) {
	log.Println(composeMessage(req))
	res.Header().Set("Content-Type", "application/json")
	res.WriteHeader(http.StatusAccepted)
	res.Write([]byte(`{"message": "put called"}`))
}

func Delete(res http.ResponseWriter, req *http.Request) {
	log.Println(composeMessage(req))
	res.Header().Set("Content-Type", "application/json")
	res.WriteHeader(http.StatusOK)
	res.Write([]byte(`{"message": "delete called"}`))
}

func NotFound(res http.ResponseWriter, req *http.Request) {
	log.Println(composeMessage(req))
	res.Header().Set("Content-Type", "application/json")
	res.WriteHeader(http.StatusNotFound)
	res.Write([]byte(`{"message": "not found"}`))
}
