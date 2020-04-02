package server

import (
	"log"
	"net/http"
)

func Home(res http.ResponseWriter, req *http.Request) {
	res.Header().Set("Content-Type", "application/json")

	switch req.Method {
	case "GET":
		res.WriteHeader(http.StatusOK)
	case "POST":
		res.WriteHeader(http.StatusCreated)
	case "PUT":
		res.WriteHeader(http.StatusAccepted)
	case "DELETE":
		res.WriteHeader(http.StatusOK)
	default:
		res.WriteHeader(http.StatusNotFound)
	}

	log.Println(composeMessage(req))
	res.Write([]byte(`{"message": "` + composeMessage(req) + `"}`))
}
