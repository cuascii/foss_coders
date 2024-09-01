/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Main.java to edit this template
 */
package chatapp;

import java.util.HashMap;
import java.util.LinkedList;
import java.util.Scanner;


public class ChatApp {

    
    public static void main(String[] args) {
        int check =1, choice;
        
        CreateChat c1=new CreateChat();
        Scanner in =new Scanner(System.in);        
        while(check==1)
        {
            System.out.println("1.New Name\n2. Display Name\n3.Check num\n4. Exit");
            choice=in.nextInt();
            switch(choice)
            {
                case 1:
                {
                    c1.newChat();
                    break;
                }
                case 2:
                {
                    c1.contactshow();
                    break;
                }
                
                case 3:
                {
                    c1.checknum();
                    break;
                }
                case 4:
                {
                    check=-1;
                    break;
                }
            }
        }
    }  
}
