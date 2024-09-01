/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package chatapp;

import java.util.HashMap;
import java.util.LinkedList;
import java.util.Scanner;

public class CreateChat {
    
    public String name=null;
    public int number= 0;
    
    LinkedList <String> chat= new LinkedList<String>();
    HashMap <Integer, String> map = new HashMap();
    Scanner in = new Scanner(System.in);
    void newChat()
    {
        System.out.print("Name: ");
        name=in.next();
        System.out.print("Number: ");
        number=in.nextInt();
        map.put(number, name);
    }
    
    void contactshow()
    {   
        System.out.println("Contact List");
        for(HashMap.Entry<Integer, String> entry:map.entrySet())
        {
            System.out.print("Name: "+entry.getValue()+"\t"+"Number: "+entry.getKey()+"\n");
        }
    }
    
    void checknum()
    {   
        System.out.println("Enter the person name");
        String nam=in.next();
        if(map.containsValue(nam))
        {
            System.out.println("Contact Already Present");
        }
        else
        {
            System.out.println("Contact Not Present");
        }
    }
}
