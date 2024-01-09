package com.example.demo;

import org.springframework.web.bind.annotation.GetMapping;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RestController;
import org.springframework.web.bind.annotation.RequestParam;


@RestController
@RequestMapping("/api")
public class HelloWorld {
    @RequestMapping("/hello")
    public String test(){
        return "Hello World!";
    }

    @GetMapping("/hello1")
    public String hello1(@RequestParam(name="name", required=false, defaultValue = "Yakshit") String name){
        return "Hello " + name;
    }
}
