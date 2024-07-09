我自己是使用windows端SSH连接远程服务器(Ubuntu 20.04), 然后访问服务器上的容器, 所以就没有办法直接使用, 这个时候就可以在容器用指令生成report, 然后下载下来用windows打开


```bash
# 打开容器的指令加一个--cap-add=SYS_ADMIN才能跑nsight compute
docker run --cap-add=SYS_ADMIN --gpus all -it --name easonbob_trt -v $(pwd):/app easonbob/my_trt-tensorrt:nsight_system

# nsight system
nsys profile --trace=cuda,nvtx -o nsight_systems_report ./trt-cuda

# nsight compute
nv-nsight-cu-cli -o nsight_compute_report ./trt-cuda
```

然后下载下来就可以直接在最新版本的nsight system和nsight compute里面打开(我自己测试过), 使用File->open, 这里下载的是windows的版本就好, 这里也附上NVIDIA的Download Center(https://developer.nvidia.com/gameworksdownload#?dn=nsight-systems-2023-3)

![在这里插入图片描述](https://img-blog.csdnimg.cn/cee90e5889c54817bd17894edc480f5b.png)
![在这里插入图片描述](https://img-blog.csdnimg.cn/c874094278014e828844138ceb3dcd11.png)


![在这里插入图片描述](https://img-blog.csdnimg.cn/3884575cae1f441fa2364eb0fea2ee79.png)

