## **1. SSH into your Rocky Linux GPU server**

```bash
ssh username@your-server-ip
```

## **4. Create a virtual environment for Jupyter**

```bash
python3 -m venv jupyter-gpu
source jupyter-gpu/bin/activate
```

---

## **5. Install Jupyter + IPython kernel + GPU packages**

```bash
pip install --upgrade pip
pip install jupyter ipykernel notebook
pip install torch torchvision torchaudio --index-url https://download.pytorch.org/whl/cu118
# or tensorflow-gpu if you want TensorFlow
```

---

## **6. Register this environment as a Jupyter kernel**

```bash
python -m ipykernel install --user --name=jupyter-gpu --display-name "Python (GPU)"
```

Now a kernel named **Python (GPU)** is available.

---

## **7. Launch Jupyter server on the remote machine**

Run:

```bash
jupyter notebook --no-browser --ip=0.0.0.0 --port=8888
```

It will output a URL with a token, e.g.:

```
http://127.0.0.1:8888/?token=xxxxxxxxxxxx
```

---

## **8. On your local machine, create an SSH tunnel to forward port 8888**

In a new terminal (on your Mac/Windows machine):

```bash
ssh -N -f -L 8888:localhost:8888 username@your-server-ip
```

Now `http://localhost:8888` on your browser connects to the server’s Jupyter.

---

## **9. Configure VS Code**

- Install **Python** and **Jupyter** extensions in VS Code.
- Open your `.ipynb` file.
- In the **top-right corner of VS Code**, click **Select Kernel** → **Existing Jupyter Server**.
- Paste the URL from step 7 (but replace `127.0.0.1` with `localhost`, since you tunneled). Example:

  ```
  http://localhost:8888/?token=xxxxxxxxxxxx
  ```

- Then select the kernel **Python (GPU)**.

---

## **10. Test GPU inside VS Code**

In a notebook cell, run:

```python
import torch
print(torch.cuda.is_available())
print(torch.cuda.get_device_name(0))
```

If it prints `True` and your GPU name, you’re good 🚀

---

From now on, you can just:

1. `ssh` into server, activate venv (`source jupyter-gpu/bin/activate`),
2. `jupyter notebook --no-browser --ip=0.0.0.0 --port=8888`,
3. Tunnel with `ssh -L 8888:localhost:8888 user@ip`,
4. Connect from VS Code.
