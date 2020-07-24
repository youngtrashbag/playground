package main

// Time is when the tweet has been created
type Time struct {
	weekday int

	day   int
	month int
	year  int

	hour   int
	minute int
	second int
}

// Tweet is litterally just the tweet as an object
type Tweet struct {
	Time Time
	Text string
}

// WordCount just calculates the word count of the tweet
func (t Tweet) WordCount() int {

}

// ProcessCreationDate takes the raw twitter JSON export and Processes it into a Time struct
func ProcessCreationDate(createdAt string) Time {

}
