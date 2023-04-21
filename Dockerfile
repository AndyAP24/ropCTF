#This will be a dockerfile for a ROP capture the flag challenge.

FROM ubuntu:latest
    RUN apt-get update && apt-get install -y build-essential\
        && apt-get clean \
        && rm -rf /var/lib/apt/lists/*
    RUN mkdir /app 
    WORKDIR /app 
    COPY rop.c /app/rop.c
    COPY hex2raw /app/hex2raw


    #Install gcc
    RUN apt-get install -y gcc\
        && apt-get clean \
        && rm -rf /var/lib/apt/lists/*

    #Compile rop.c
    RUN gcc -o rop rop.c -fno-stack-protector -no-pie -z execstack

    #Clean up build
    RUN rm -rf /app/rop.c

    RUN apt-get update \
        && apt-get install -y \
        openssh-server\
        nano\
        gdb\
        && apt-get clean \
        net-tools \
        && rm -rf /var/lib/apt/lists/*

    EXPOSE 22
    


    #Make a user with credentials labuser:labuser
    RUN adduser --disabled-password --gecos "" labuser && echo 'labuser:labuser' | chpasswd 

    #Give user permissions to run and create files in /app
    RUN chown -R labuser:labuser /app

    RUN chmod 777 /app

    #Give everyone the permissions to execute hex2raw
    RUN chmod 777 /app/hex2raw

    

    #Make it so that you cannot ssh in as root
    RUN sed -i 's/PermitRootLogin prohibit-password/PermitRootLogin no/' /etc/ssh/sshd_config

    #Make it so that you are not prompted for a password when sshing in as labuser
    RUN echo 'labuser ALL=(ALL) NOPASSWD:ALL' >> /etc/sudoers


    ENTRYPOINT service ssh start && tail -f /dev/null

    

    #Restric the user to this directory
    WORKDIR /app

    



