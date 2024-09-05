#include <stdio.h>
#include <sys/socket.h>
#include <netdb.h>
#include <ifaddrs.h>

int main()
{
    char ip_address[100];
    int ipv4_family_size;
    int ipv6_family_size;
    struct ifaddrs *addresses;

    // getifaddrs() allocates memory and creates a linked list of a`struct ifaddrs' structures
    if (getifaddrs(&addresses) == 0)
    {
        ipv4_family_size = sizeof(struct sockaddr_in);
        ipv6_family_size = sizeof(struct sockaddr_in6);

        // Iterate the link list of 'struct ifaddrs' structures
        struct ifaddrs *address = addresses;
        while (NULL != address)
        {
            // Identify the address family. We are only interested in Internet addresses
            int family = address->ifa_addr->sa_family;
            if (family == AF_INET || family == AF_INET6)
            {
                // Print interface name
                printf("%s\t", address->ifa_name);

                // Print family
                printf("%s\t", family == AF_INET ? "IPv4" : "IPv6");

                // Print IP address
                // NI_NUMERICHOST - numeric form of the hostname
                if (family == AF_INET)
                {
                    getnameinfo(address->ifa_addr, ipv4_family_size, ip_address, sizeof(ip_address), 0, 0, NI_NUMERICHOST);
                }
                else // (family == AF_INET6)
                {
                    getnameinfo(address->ifa_addr, ipv6_family_size, ip_address, sizeof(ip_address), 0, 0, NI_NUMERICHOST);
                }
                printf("%s\n", ip_address);
            }

            // Go to the next address in the inked list
            address = address->ifa_next;
        }
        // We are responsible to release memory allocated in getifaddrs()
        freeifaddrs(addresses);
    }
    return 0;
}
