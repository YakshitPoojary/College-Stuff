package com.example.orderservice;

import java.util.ArrayList;
import java.util.List;

import org.springframework.web.bind.annotation.GetMapping;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RequestParam;
import org.springframework.web.bind.annotation.RestController;

@RestController
@RequestMapping("/api")
public class FruitsController {
    private List<Fruits> fruitsList = new ArrayList<>();

    public FruitsController() {
        getFruitsName();
    }

    private void getFruitsName(){
        Fruits apple = new Fruits();
        apple.setName("Apple", 10, 50);
        Fruits mango = new Fruits();
        mango.setName("Mango", 20, 100);
        Fruits orange = new Fruits();
        orange.setName("Orange", 5, 30);
        Fruits banana = new Fruits();
        banana.setName("Banana", 2, 10);

        fruitsList.add(apple);
        fruitsList.add(mango);
        fruitsList.add(orange);
        fruitsList.add(banana);
    }

    @GetMapping("/list")
    public List<Fruits> getAllFruits() {
        return fruitsList;
    }

    @GetMapping("/getFruitAndQuantity")
    public Fruits getFruitByName(
            @RequestParam(value = "fruitName", required = false) String fruitName,
            @RequestParam(value = "quantity", required = false) Integer quantity) {

        if (fruitName != null && quantity != null && quantity > 0) {
            for (Fruits fruit : fruitsList) {
                if (fruit.getName().equalsIgnoreCase(fruitName) && fruit.getQuantity() >= quantity) {
                    fruit.setQuantity(fruit.getQuantity() - quantity);
                    return fruit;
                }
            }
        }
        return null;
    }

    @GetMapping("/getFruit")
    public Fruits getFruitByName(@RequestParam(value = "fruitName", required = false) String fruitName) {
        if (fruitName != null) {
            for (Fruits fruit : fruitsList) {
                if (fruit.getName().equalsIgnoreCase(fruitName)) {
                    return fruit;
                }
            }
        }
        return null;
    }

}
