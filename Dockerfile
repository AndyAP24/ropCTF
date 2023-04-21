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


    #Make a user with credentials labuser:labuser
    RUN useradd -m labuser
    RUN echo "labuser:labuser" | chpasswd

    RUN service ssh start


    EXPOSE 22
    
    #I want people to be able to ssh into the container with labuser@IP and the password labuser

    RUN mkdir /home/labuser/.ssh
    RUN chmod 700 /home/labuser/.ssh
    RUN chown labuser:labuser /home/labuser/.ssh

    USER labuser

    RUN ssh-keygen -t ed25519 -f /home/labuser/.ssh/id_ed25519 -N ''

    RUN cat /home/labuser/.ssh/id_ed25519.pub >> /home/labuser/.ssh/authorized_keys

    USER root

    RUN chmod 600 /home/labuser/.ssh/authorized_keys
    RUN chown labuser:labuser /home/labuser/.ssh/authorized_keys

    #Make sure the ssh server doesn't ask for confirmation or password

    RUN echo "Host *\n\tStrictHostKeyChecking no\n\n" > /home/labuser/.ssh/config
    RUN echo "PasswordAuthentication no" >> /etc/ssh/sshd_config

    #Disable root login
    RUN echo "PermitRootLogin no" >> /etc/ssh/sshd_config
    USER root

    CMD [ "/usr/sbin/sshd", "-D" ]

    

    #Restric the user to this directory
    WORKDIR /app

    



