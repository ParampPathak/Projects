# Proxmox Homelab

Self-hosted homelab built on Proxmox VE for virtualization, containerization, network services, monitoring, observability, media streaming, and home automation.

## Architecture

```text
                         Home Network
                              |
              +---------------+---------------+
              |                               |
         Raspberry Pi                    Proxmox VE
              |                               |
           Pi-hole                 +----------+----------+
        DNS / Ad Blocking          |                     |
                            Home Assistant VM       Ubuntu Server VM
                                                         |
                                                       Docker
                                                         |
                           +-----------------------------+------------------+
                           |              |              |                 |
                        Jellyfin      Uptime Kuma     Monitoring         Homepage
                                                       |
                                             +---------+---------+
                                             |                   |
                                         Prometheus           Grafana
                                             |
                                       Node Exporter
```

## Hardware

### Proxmox Host

- Intel Celeron N5095
- 4 CPU cores
- 12 GB DDR4 RAM
- 512 GB SSD
- Proxmox VE

### Raspberry Pi

- Raspberry Pi
- Dedicated Pi-hole DNS server

## Virtual Machines

### Home Assistant

Dedicated Home Assistant OS virtual machine.

- 2 vCPU
- 4 GB RAM
- 32 GB storage
- Smart-home device management and automation

### Ubuntu Docker Server

Ubuntu Server VM hosting containerized services.

- 4 vCPU
- 4 GB RAM
- 200 GB virtual disk
- Docker
- Docker Compose

## Services

### Jellyfin

Self-hosted media server used to organize and stream locally stored media.

### Uptime Kuma

Service availability monitoring for:

- Pi-hole
- Home Assistant
- Jellyfin
- Prometheus
- Grafana
- Node Exporter

### Prometheus

Collects time-series infrastructure metrics from Node Exporter.

Metrics include:

- CPU utilization
- Memory utilization
- Disk utilization
- Network throughput
- System uptime

### Grafana

Visualizes Prometheus metrics through a custom infrastructure dashboard.

Dashboard includes:

- CPU utilization
- RAM utilization
- Disk utilization
- System uptime
- Network traffic

### Node Exporter

Exports Linux host metrics from the Ubuntu Docker server to Prometheus.

### Homepage

Centralized web dashboard providing access to homelab services and infrastructure information from a single interface.

### Pi-hole

Dedicated Raspberry Pi providing network-wide DNS filtering and ad blocking.

### Home Assistant

Virtualized smart-home management platform integrating supported IoT devices and home automation services.

## Monitoring Architecture

```text
Ubuntu Server
     |
Node Exporter
     |
     | :9100
     v
Prometheus
     |
     | PromQL
     v
Grafana
     |
     v
Monitoring Dashboard


Uptime Kuma
     |
     +-- Pi-hole
     +-- Home Assistant
     +-- Jellyfin
     +-- Prometheus
     +-- Grafana
     +-- Node Exporter
```

## Networking

Services are hosted on the private home LAN.

| Service | Port |
| --- | ---: |
| Jellyfin | 8096 |
| Uptime Kuma | 3001 |
| Grafana | 3000 |
| Prometheus | 9090 |
| Node Exporter | 9100 |
| Home Assistant | 8123 |
| Homepage | 3002 |

Administrative services are not intentionally exposed directly to the public Internet.

## Technologies

- Proxmox VE
- Linux
- Ubuntu Server
- Docker
- Docker Compose
- Home Assistant
- Jellyfin
- Uptime Kuma
- Prometheus
- Grafana
- Node Exporter
- Pi-hole
- SSH
- DNS
- TCP/IP
- Virtualization
- Containerization
- Infrastructure Monitoring
- Observability

## Repository Structure

```text
homelab/
├── README.md
├── .gitignore
├── docker/
│   ├── jellyfin/
│   │   └── compose.yaml
│   ├── monitoring/
│   │   ├── compose.yaml
│   │   └── prometheus.yml
│   ├── uptime-kuma/
│   │   └── compose.yaml
│   └── homepage/
│       ├── compose.yaml
│       ├── services.yaml
│       └── widgets.yaml
└── screenshots/
    ├── homepage.png
    ├── grafana.png
    ├── uptime-kuma.png
    ├── jellyfin.png
    └── home-assistant.png
```
## Security

Sensitive application data is excluded from this repository.

The following are not committed:

- Passwords
- API keys
- Private keys
- Certificates
- Environment files containing secrets
- Jellyfin media
- Application databases
- Persistent container data

Private LAN addresses in example configuration files can also be replaced with placeholders before publishing.

## Future Improvements

- Centralized Docker management
- Additional Grafana dashboards and Prometheus exporters
- Alerting
- Automated configuration deployment
- Kubernetes/K3s learning environment
- Argo CD
- GitOps
- Infrastructure as Code
