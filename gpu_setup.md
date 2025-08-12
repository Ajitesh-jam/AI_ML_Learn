# install conda

```
brew install --cask miniforge

```

check by seeing
`which python` , it should be `/opt/homebrew/Caskroom/miniforge/base/envs/tf-metal/bin/python`

# to activate new gpu terminal

```
conda activate tf_numpy2

# Installs the ipykernel package into your active environment
conda install ipykernel -y

# Register the kernel with Jupyter
python -m ipykernel install --user --name=tf_numpy2 --display-name="Python (tf_numpy2)"

```

and restart the kernel

to verify,
`cat ~/Library/Jupyter/kernels/tf-metal/kernel.json`
and you should see like

```
{
  "argv": [
    "/opt/homebrew/Caskroom/miniforge/base/envs/tf-metal/bin/python",
    "-m",
    "ipykernel_launcher",
    "-f",
    "{connection_file}"
  ],
  "display_name": "numpy2",
  "language": "python"
}
```

# uninstall no longer
