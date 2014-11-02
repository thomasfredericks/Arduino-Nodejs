function ArduinoClient(adresseDuServeur, onOpen) {
    
    var self = this;

	//  Map implementation differences to single reference
	window.WebSocket = window.WebSocket || window.MozWebSocket;		
	//  Instantiate the web socket
	socket = new WebSocket( 'ws://'+adresseDuServeur );
    
    //  Attach event handlers
    
	//  Attach event handlers
	socket.onmessage = function(message) {
         if (self.onMessage ) self.onMessage(message);
         if (self.onMassage) {
             var wordArray = message.data.split(" ");
            // S'assurer qu'on a au moins deux mots.
            if ( wordArray.length > 1 ) {
                var firstWord = wordArray[0];
                var secondWord = wordArray[1];
                // Vérifier si le premier mot du message est "a0".
                self.onMassage(firstWord,parseFloat(secondWord));
            }
             
         }
          
        
    };
	
    if (onOpen)
          onOpen();
   
    

}