package com.example.microservicea;

public class Student {
    private String firstName;
    private String lastName;
    private String departmentName;

    public void setName(String firstName, String lastName, String departmentName){
        this.firstName = firstName;
        this.lastName = lastName;
        this.departmentName = departmentName;
    }

    public String getName(){
        return firstName + " " + lastName + " from branch " + departmentName;
    } 
}