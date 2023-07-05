
        Node temp3 = temp;
        if(key == temp->data){
            if(head == temp){
                head = delete_from_beg(head);
            }
            else if(temp->next == NULL){
                head = delete_from_end(head);
            }
            else{
                printf("hi2\n");