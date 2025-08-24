reate a Conda Environment for TensorFlow with GPU
After Miniforge installs, restart Terminal. Then:

bash
Copy
Edit
conda create -n tf-metal python=3.9
conda activate tf-metal
Install Apple Silicon–optimized TensorFlow:

bash
Copy
Edit
pip install tensorflow-macos
pip install tensorflow-metal
Step 4: Test GPU Access in Your Python Notebook
In your VS Code .ipynb file, insert this:

python
Copy
Edit
import tensorflow as tf

print("Num GPUs Available:", len(tf.config.list_physical_devices('GPU')))
You should see:

yaml
Copy
Edit
Num GPUs Available: 1
Also, logs should say:

swift
Copy
Edit
Metal device set to: Apple M1/M2/M3

<gpu.png>
