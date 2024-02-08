package com.example.orderservice;
import org.springframework.web.bind.annotation.GetMapping;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RestController;

@RestController
@RequestMapping("/api")
public class OrderserviceController{
    @GetMapping("/message")
    public String getMessage() 
    {
        return "Hello from Microservice A!";
    }
}