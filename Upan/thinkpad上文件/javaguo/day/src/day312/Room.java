package day312;

import java.util.HashMap;





public class Room {
    private String description;
   private HashMap<String, Room> exits=new HashMap<String, Room>();
    
//    private Room northExit;
//    private Room southExit;
//    private Room eastExit;
//    private Room westExit;

    public Room(String description) 
    {
        this.description = description;
    }
    public String returndie(){
//    	StringBuffer sBuffer=new StringBuffer();
//    	for (String k: exits.keySet()) {
//			if(k.equals("north")){
//				  sBuffer.append("north ");
//			}
//			if (k.equals("east ")) {
//				sBuffer.append("east ");
//			}
//			if (k.equals("south ")) {
//				 sBuffer.append("south ");
//			}
//			if (k.equals("east")) {
//				  sBuffer.append("west ");
//			}
//		}
    	return exits.keySet().toString() ;
    	
    }
    	
public Room  setgotoroom(String direction){
	  Room ret = null;
	 
      return exits.get(direction);
      
}
    public void setExit(String des,Room room)
    
    {
     exits.put(des, room);
     
    }

    @Override
    public String toString()
    {
        return description;
    }
}
