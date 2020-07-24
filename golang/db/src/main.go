package main

import (
	"database/sql"
	"fmt"

	_ "github.com/go-sql-driver/mysql"
)

func main() {
	fmt.Println("hello world")
	db, err := sql.Open("mysql", "test_user:password@/test_db")
	if err != nil {
		panic(err.Error())
	}
	defer db.Close()

	var test tableTest
	test.field1 = "ok"
	test.field2 = "field2 info"

	id := test.InsertToDB(db)

	existingTable := GetTTByID(db, id)

	existingTable.PrintInfos()
}

type tableTest struct {
	id     int64
	field1 string
	field2 string
}

func (tt *tableTest) PrintInfos() {
	fmt.Printf("id:\t%d\n", tt.id)
	fmt.Printf("field1:\t%s\n", tt.field1)
	fmt.Printf("field2:\t%s\n", tt.field2)
}

func (tt *tableTest) InsertToDB(db *sql.DB) int64 {
	ins, err := db.Prepare("INSERT INTO test_db.table (field1, field2) VALUES (?, ?);")
	if err != nil {
		panic(err.Error())
	}
	defer ins.Close()

	res, err := ins.Exec(tt.field1, tt.field2)
	if err != nil {
		panic(err.Error())
	}

	//maybe return last insert id (because inerst can be ignored)
	id, err := res.LastInsertId()
	if err != nil {
		panic(err.Error())
	}

	return id
}

func GetTTByID(db *sql.DB, id int64) tableTest {
	tagRows, err := db.Query("SELECT id, field1, field2 FROM test_db.table WHERE id = ?;", id)
	if err != nil {
		panic(err.Error())
	}
	defer tagRows.Close()

	var tt tableTest
	for tagRows.Next() {
		err := tagRows.Scan(&tt.id, &tt.field1, &tt.field2)
		if err != nil {
			panic(err.Error())
		}
	}

	err = tagRows.Err()
	if err != nil {
		panic(err.Error())
	}

	return tt
}
