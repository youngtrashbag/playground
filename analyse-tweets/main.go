package main

import (
	"fmt"
	"os"
)

/*
	The Format of the tweet in the JSON looks something like this:
	"created_at" : "Sat Mar 28 10:16:05 +0000 2020"

	So Essentially it is just:
	"created_at": "Weekday Month Day Hour:Minute:Second +Tmezone Year"
	The Weekday and Month are strings, but I will save them in the Objects as integers.
*/

func main() {
	var weekdays = []string{"Mon", "Tue", "Wed", "Thu", "Fri", "Sat", "Sun"}
	var months = []string{"Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"}

	var filename string = "tweets.js"

	jsonfile, err := os.Open(filename)

	if err != nil {
		fmt.Println(err)
	}

	defer jsonfile.Close()

	fmt.Println("Successfully Opened " + filename + " !")

}
