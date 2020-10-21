chmod ugo-x _ex3.txt # removing execute for everybody
chmod uo+rwx _ex3.txt # granting all permissions to owners and others 
chmod g=u _ex3.txt # group permissions equal user permissions

# 066 is 110 110 000 or rw-rw---- read-write permissions for user and group
# 775 is 111 111 101 or rwxrwxr-x all permissions for user and group, but only read-execute for others
# 777 is 111 111 111 or rwxrwxrwx all permissions for all
