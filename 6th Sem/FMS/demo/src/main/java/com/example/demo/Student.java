package com.example.demo;

public class Student {
    private String firstName;
    private String lastName;

    public void setName(String firstName, String lastName){
        this.firstName = firstName;
        this.lastName = lastName;
    }

    public String getName(){
        return firstName + " " + lastName;
    } 
}
