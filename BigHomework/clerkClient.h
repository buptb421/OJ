#ifndef _CLERKCLIENT_H
#define _CLERKCLIENT_H

#define NAMELEN 6	   				   
#define DEFAULT_TERMINAL_WIDTH 80
#define DEFAULT_TERMINAL_HEIGHT 60

#define CLEAR_SCREEN "clear"
//#define CLEAR_SCREEN "cls"

typedef struct item_info{  				   
    char name[NAMELEN];	   				   
    int price100;	   				   
    int remain_num;	   				   
    struct item_info *next;				   
}item;			   				   

#endif
/*			   				   
  The structure of item:              	  		   
    			   				   	  
    +-------------------------+----------+     	 	   	  
    | DATA:            	      |POINTER:	 | 	 	   	  
    |   name, price, remain   |	 next  	 |     	 	   	  
    +-------------------------+----------+		   	  
			   				   	  
  The structure of the list:				   	  
			   				   	  
   +------------------------------------------------------------------------------+
   |int main()                                                                    |	    
   |{  	      		   		                                          |	    
   |   	  item *head;--+       item *newitem;--+       	       	       	          |
   |   	       	       |       	       	       |       	       	       	    	  |
   |   	       	       |       	       	       |       	       	     	    	  |
   |   		       |       	       	       |       	       	       	       	  |
   |}  		       |   		       |	   	     	    	  |
   +-------------------+-----------------------+----------------------------------+
       		       |   		       |	   	  
       		       |   		       +-----------------------------------------------+
       	       	       |       	       	       	       	       	       	       	     	       |
       	       	       |   		       	       	   	     		     	       |
       	       	       |       empty item     	   water             food  	     	       |
                       |    +-----------+--+   +------------+--+   +-------------+--+  	       |
       	       	       +--> |  	       	|  |-->|    	    |  |-->|   	       	 |  |-->NULL   |
       		       	    +-----------+--+   +------------+--+   +-------------+--+	       |
       		       	      this empty item		   	     			       |
       		       	      is used to make		   	     			       |
       		       	      operations easier.	   	     			       |
       	       	       	   				   	     			       |
   Insert operation:   	   				   	     			       |
 main(){item *head;}  	       	       	  		   	       	       	       	       |               
 |   +-------------+--+	  +--------+--+   +-------------+--+   +--------+--+		       |	      
 +-->| 	 empty 	   |  |-->| 1  	   |  |-->|2   	       	|  |-->|4      	|  |-->NULL    	       |	      
     +-------------+--+	  +--------+--+	  +-------------+--+   +--------+--+           	       |	      
     	  		   		                                        +--------------+	      
     	  		   				   	  	  	v  			      
     	  		   				   	  	 +----------+--+		      
       	       	      	   				       	       	 |   3	    |  |		      
       	       	       	       	       	       	       	       	       	 +----------+--+		      
     	  		   				   	  	  	   			      
     	  		   				   	  	  	   			      
     then, go into the specific fuction, like a function called insertnode(),         	       	       	       	   
  +---------------------------------------------------------------+					      
  |insertnode()       	       	       	       	       	       	  |    	   				      
  |   item *insertposition;+   	       	       	       	       	  |					      
  |   item *newitem+       |           	       	       	       	  |
  +----------------+-------+--------------------------------------+
  	           |   	   |				   
  	           |   	   |				   
	  +--------+   	   v				   
       	  |    +-----------------+--+ 	  +--------------+--+			     
       	  |    |  2    	       	 |  | --->|  4 	       	 |  |--->......		     
	  |    +-----------------+--+  	  +--------------+--+			     
	  |	    					   			     
	  |	    					   			     
	  |	    +----------+----+			   			     
	  +-------> | 3	       |    |--->NULL		   			     
		    +----------+----+	     		   			     
					     		   			     
							   			     
   imagine adding a carriege into a train by switching the turnout on parallel rails:
    ------------------------------------------------	   			     
 	 insertposition        	       	newitem	    	   			     
    -----------+---------------------------+--------	   			     
       	       |			   |		   			     
	       |			   V		   			     
	       |		       +--------+--+	   			     
	       |       	       	       |3      	|  |\  	     
	       |		       +--------+--+ \-	     
	       |       	       	       	       	       \-    
	       V				         \-  
	  +-------+--+				           \-     +--------+--+
	  | 2  	  |  |---------------------------------------\--->|4   	   |  |-->......
	  +-------+--+				     	   	  +--------+--+
						     	   
						     	   
    then, let 2 point to 3:    			     	   
    ------------------------------------ 		   
    insertposition    newitem         	       	       	       	     
    	 |		  |				   
    -----+----------------+-------------		   
         |		  |				   
         |     	       	  |				   
         |		  |				   
         |		  V				   
         |	       +-----+--+			   
       	 |	      /|3    | 	|\			   
       	 |	     / +-----+--+ \			   
       	 |	   /- 		   \			   
       	 V	  /   		    \			   
     +------+--+ /    		     \	+----+--+	   
     |2	    |  |/		      \	|4   | 	|--->......
     +------+--+  	       		+----+--+	   
		       	       				   





*/     	       	       	     
	  
