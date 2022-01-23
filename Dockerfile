# Base: https://github.com/binder-examples/minimal-dockerfile
FROM python:3.9-slim
MAINTAINER Brian Chen <brianchen.chen@mail.utoronto.ca

RUN apt-get update && apt-get install -y build-essential

RUN pip install --no-cache --upgrade pip && \
    pip install --no-cache notebook jupyterlab jupyter-c-kernel jupyterhub



ARG NB_USER=jovyan
ARG NB_UID=1000
ENV USER ${NB_USER}
ENV NB_UID ${NB_UID}
ENV HOME /home/${NB_USER}

RUN adduser --disabled-password \
    --gecos "Default user" \
    --uid ${NB_UID} \
    ${NB_USER}

RUN install_c_kernel

# Make sure the contents of our repo are in ${HOME}
COPY . ${HOME}
USER root
RUN chown -R ${NB_UID} ${HOME}
USER ${NB_USER}

WORKDIR ${HOME}
















