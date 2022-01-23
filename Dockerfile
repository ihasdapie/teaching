# Base: https://github.com/binder-examples/minimal-dockerfile

FROM python:3.9-slim
# install the notebook package


RUN apt-get update && apt-get install -y build-essential

RUN pip install --no-cache --upgrade pip && \
    pip install --no-cache notebook jupyterlab jupyter-c-kernel

RUN install_c_kernel


# create user with a home directory
# ARG NB_USER
# ARG NB_UID
# ENV USER ${NB_USER}
# ENV HOME /home/${NB_USER}

# RUN adduser --disabled-password \
#     --gecos "Default user" \
#     --uid ${NB_UID} \
#     ${NB_USER}
    
# WORKDIR ${HOME}
# USER ${USER}


















