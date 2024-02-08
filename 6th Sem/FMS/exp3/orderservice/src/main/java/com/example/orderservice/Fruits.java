package com.example.orderservice;

public class Fruits {
    private String fruitName;
    private int fruitQuantity;
    private int fruitPrice;

    public void setName(String firstName, int fruitPrice, int fruitQuantity){
        this.fruitName = firstName;
        this.fruitPrice = fruitPrice;
        this.fruitQuantity = fruitQuantity;
    }

    public String getName(){
        return fruitName;
    } 

    public int getPrice(){
        return fruitPrice;
    } 

    public int getQuantity(){
        return fruitQuantity;
    } 

    public void setQuantity(int newQuantity) {
        this.fruitQuantity = newQuantity;
    }
}
