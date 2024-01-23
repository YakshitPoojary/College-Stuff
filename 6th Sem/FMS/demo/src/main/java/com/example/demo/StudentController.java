package com.example.demo;

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
        Student student = new Student();
        student.setName("Yakshit", "Poojary");
        Student student2 = new Student();
        student2.setName("Isha", "Kanda");

        studentList.add(student);
        studentList.add(student2);
    }

    @GetMapping("/list")
    public List<Student> getAllStudents() {
        return studentList;
    }
}
