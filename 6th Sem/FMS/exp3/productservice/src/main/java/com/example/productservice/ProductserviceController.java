package com.example.productservice;

import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.web.bind.annotation.GetMapping;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RequestParam;
import org.springframework.web.bind.annotation.RestController;
import org.springframework.web.client.RestTemplate;

@RestController
@RequestMapping("/api")
public class ProductserviceController {
    @Autowired
    private RestTemplate restTemplate;

    @GetMapping("/orderservicetest")
    public String orderServiceTest() {
        String orderServiceTest = restTemplate.getForObject("http://localhost:8080/api/list", String.class);
        return "Fruits List: " + orderServiceTest;
    }

    @GetMapping("/fruits")
    public String fruits(
            @RequestParam(value = "fruitName", required = false) String fruitName,
            @RequestParam(value = "quantity", required = false) Integer quantity) {

        String fruitResponse = restTemplate.getForObject("http://localhost:8080/api/getFruitAndQuantity?fruitName=" + fruitName + "&quantity=" + quantity, String.class);
        return "Fruit: " + fruitResponse;
    }
}
