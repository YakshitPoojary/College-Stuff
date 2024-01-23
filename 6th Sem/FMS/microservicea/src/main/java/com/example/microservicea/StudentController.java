package com.example.microservicea;

import org.springframework.web.bind.annotation.GetMapping;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RestController;

import java.util.ArrayList;
import java.util.List;

@RestController
@RequestMapping("/students")
public class StudentController {

    private List<Student> studentList = new ArrayList<>();

    public StudentController() {
        getStudentInfo();
    }

    private void getStudentInfo() {
        Student student1 = new Student();
        student1.setName("Yakshit", "Poojary", "COMPS");
        Student student2 = new Student();
        student2.setName("Isha", "Kanda", "ETRX");
        Student student3 = new Student();
        student3.setName("Himan", "Patil", "IT");
        Student student4 = new Student();
        student4.setName("Anuj", "Venka", "EXTC");

        studentList.add(student1);
        studentList.add(student2);
        studentList.add(student3);
        studentList.add(student4);
    }

    @GetMapping("/list")
    public List<Student> getAllStudents() {
        return studentList;
    }
}
