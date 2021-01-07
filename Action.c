Action()
{
	
	int i;
	char* s;
	int interupt;
	char* z;
	int currentpage;
	
		while ( i == 0) {
		
		lr_save_int(currentpage, "CurrentPage");
		
		web_reg_find("Text=Amstrad",
		"SaveCount=CountPovtor",	             
		LAST);
		
		web_reg_find("Text=Nothing to display",
		"SaveCount=CountForBreak",	             
		LAST);
		    
		web_url("Next &rarr;", 
		"URL=http://computer-database.gatling.io/computers?p={CurrentPage}", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=http://computer-database.gatling.io/computers", 
		"Snapshot=t3.inf", 
		"Mode=HTML", 
		LAST);
			
		s = lr_eval_string("{CountPovtor}");
		i = atoi(s);
		lr_output_message("Chislo povtoreniy: %s",lr_eval_string("{CountPovtor}"));
		
		z = lr_eval_string("{CountForBreak}");
		interupt = atoi(z);
		lr_output_message("CountForBreak: %s",lr_eval_string("{CountForBreak}"));
		
		lr_output_message("CurrentPage: %s",lr_eval_string("{CurrentPage}"));
		
		if ( interupt == 1 ) {
			
		break;    
		
		}
		 
		currentpage = currentpage + 1;
		
		}
		
		if ( i == 0) {
			
		lr_output_message("No exist page with such Company");
		
		}
			
		if ( i >= 1) {
			
		lr_output_message("Required PageNumber is: %s",lr_eval_string("{CurrentPage}"));
	
		}
	
	return 0;
}
