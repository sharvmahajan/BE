// SPDX-License-Identifier: MIT
pragma solidity ^0.8.0;

contract StudentData{
    struct Student{
        string name;
        uint age;
        string class;
        uint rollNo;
    }

    Student[] students;

    function getTotalStudents() public view returns (uint){
        return students.length;
    }

    function addStudent(string memory name, uint age, string memory class, uint rollNo) public {
        students.push(Student(name, age, class, rollNo));
    }

    function getStudent(uint i) public view returns (string memory name, uint age, string memory class, uint rollNo) {
        require(i >= 0 && i < students.length, "Invalid Index");
        return (students[i].name, students[i].age, students[i].class, students[i].rollNo);
    }
}
