package main

import (
	"encoding/json"
	"fmt"
	"io"
	"net/http"
	"time"
)


type User []struct {
	ID       int    `json:"id"`
	Name     string `json:"name"`
	Username string `json:"username"`
	Email    string `json:"email"`
	Address  struct {
		Street  string `json:"street"`
		Suite   string `json:"suite"`
		City    string `json:"city"`
		Zipcode string `json:"zipcode"`
		Geo     struct {
			Lat string `json:"lat"`
			Lng string `json:"lng"`
		} `json:"geo"`
	} `json:"address"`
	Phone   string `json:"phone"`
	Website string `json:"website"`
	Company struct {
		Name        string `json:"name"`
		CatchPhrase string `json:"catchPhrase"`
		Bs          string `json:"bs"`
	} `json:"company"`
}


func networkGET() (User, error){
	client := &http.Client{
		Timeout: time.Second * 10,
	}
	
	req, err := http.NewRequest("GET", "https://jsonplaceholder.typicode.com/users", nil)
	if err != nil {
		return User{}, err
	}

	res , err := client.Do(req)

	if err != nil {
		return User{}, err
	}

	defer res.Body.Close()

	if res.StatusCode > 399 {
		return User{}, fmt.Errorf("Bad status code: %v", res.StatusCode)
	}

	data, err := io.ReadAll(res.Body)
	if err != nil {
		return User{}, err
	}

	user := User{}

	err = json.Unmarshal(data, &user)

	if err != nil {
		return User{}, err
	}

	return user, nil
}