/* Copyright 2003 IP Infusion, Inc. All Rights Reserved.  */

#ifndef _NETLK_COMM_H_
#define _NETLK_COMM_H_
#define NETL_MSG_PROCESS_RETURN(SOCK,HDR,RET)                                                       \
       do {                                                                                        \
            if ((HDR)->nlmsg_flags & NETL_NLM_F_ACK)                                                \
              {                                                                                    \
                if ((RET) < 0)                                                                     \
                 netlk_sock_post_ack ((SOCK), (HDR), 0, -1);                                         \
                else                                                                               \
                 netlk_sock_post_ack ((sock), (HDR), 0, 0);                                          \
              }                                                                                    \
       } while (0)


/* Structure to hold the NL control per socket. */
struct netlk_sock
{
  u_int32_t groups;       /* Multicast groups. */
  u_int32_t pid;          /* PID. */
  struct sock *sk;        /* Pointer to the sock structure. */
  struct netlk_sock *next;  /* Next pointer. */
};

/* function prototypes. */
int netlk_sock_init (void);
int netlk_sock_deinit (void);
int netlk_sock_process_msg (struct socket *sock, char *buf, int buflen);
int netlk_sock_process_msg (struct socket *sock, char *buf, int buflen);
int netlk_sock_post_buffer (struct socket *sock, char *buf, int size);
int netlk_sock_post_msg (struct socket *sock, int cmd, int flags, int seqno, char *buf, int size);
int netlk_sock_post_ack (struct socket *sock, struct netl_nlmsghdr *hdr, int flags, int error);
int netlk_sock_release (struct socket *sock);

#endif /* _NETLK_COMM_H_ */
