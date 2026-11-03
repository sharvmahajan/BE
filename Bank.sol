// SPDX-License-Identifier: MIT
pragma solidity ^0.8.0;

contract Bank{
    address owner;

    constructor(){
        owner = msg.sender;
    }
    function ownerName() public view returns (address){
        return owner;
    }
    function deposit() public payable {
        require(msg.value > 0, "Invalid Amount");
    }

    function withdraw(uint x) public{
        require(msg.sender == owner, "Not owner");
        require(x > 0 && x <= address(this).balance, "Insufficient balance");
        payable(owner).transfer(x);
    }

    function getBalance() public view returns (uint){
        return address(this).balance;
    }
    function getOwnerBalance() public view returns (uint){
        return owner.balance;
    }
    function getSelfBalance() public view returns (uint){
        return msg.sender.balance;
    }
}
