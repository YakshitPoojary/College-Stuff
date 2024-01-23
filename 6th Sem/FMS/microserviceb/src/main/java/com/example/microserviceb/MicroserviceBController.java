package com.example.microserviceb;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.web.bind.annotation.GetMapping;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RestController;
import org.springframework.web.client.RestTemplate;
import org.springframework.web.bind.annotation.RequestParam;

@RestController
@RequestMapping("/api")
public class MicroserviceBController{
    @Autowired
    private RestTemplate restTemplate;

    @GetMapping("/microservicea")
    public String communicateWithMicroserviceA() {
        String microserviceAResponse = restTemplate.getForObject("http://localhost:8080/api/message", String.class);
        return "Microservice A Communication result: " + microserviceAResponse;
    }

    @GetMapping("/microservicea/students/list")
    public String microserviceAStudents() {
        String microserviceAstudents = restTemplate.getForObject("http://localhost:8080/students/list", String.class);
        return "Microservice A Communication result: " + microserviceAstudents;
    }

    @GetMapping("/demo")
    public String demo() {
        String demoResponse = restTemplate.getForObject("http://localhost:8082/students/list", String.class);
        return "Demo Communication result: " + demoResponse;
    }
    
}