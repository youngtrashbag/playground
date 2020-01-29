package main

import (
	"log"
	"net/http"
	"well-rested/server"
	"github.com/gorilla/mux"
)

func main() {

	log.Println("Starting Server...")

	//new router
	r := mux.NewRouter()
	//new subrouter
    api := r.PathPrefix("/api/").Subrouter()
    api.HandleFunc("", server.Get).Methods(http.MethodGet)
    api.HandleFunc("", server.Post).Methods(http.MethodPost)
    api.HandleFunc("", server.Put).Methods(http.MethodPut)
    api.HandleFunc("", server.Delete).Methods(http.MethodDelete)
	api.HandleFunc("", server.NotFound)

	//pet resource
	pet := r.PathPrefix("/pet/").Subrouter()
    pet.HandleFunc("", pet.Get).Methods(http.MethodGet)
    pet.HandleFunc("", pet.Post).Methods(http.MethodPost)
    pet.HandleFunc("", pet.Put).Methods(http.MethodPut)
    pet.HandleFunc("", pet.Delete).Methods(http.MethodDelete)
	pet.HandleFunc("", pet.NotFound)
	
	log.Println("Server Running...")
	defer log.Println("Server Stopped")

	log.Fatal(http.ListenAndServe(":8080", r))
}
