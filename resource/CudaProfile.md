## Nsight System使用
```bash
nsys profile --trace=cuda,nvtx -o nsight_systems_report ./cudaProgramOut
nsys profile --trace=cuda,cublas,nvtx  -gpu-metrics-device=0 --stats=false -o nsight_systems_report ./cudaProgramOut
nsys profile --trace=cuda,cublas,nvtx  -gpu-metrics-device=1 --stats=false -o nsight_systems_report ./cudaProgramOut
nsys profile --trace=cuda,cublas,nvtx,osrt,cudnn  -gpu-metrics-device=0,1 --stats=false -o nsight_systems_report ./cudaProgramOut
nsys profile --trace=cuda,cublas,nvtx,osrt,cudnn  -gpu-metrics-device=0,1,2,3 --stats=false -o nsight_systems_report ./cudaProgramOut
nsys status -e
```

## Nsight Compute使用

```bash
ncu -o profile ./cudaProgramOut

ncu --set full --section MemoryWorkloadAnalysis_Tables -o profile ./cudaProgramOut

# 多卡 profile
ncu --replay-mode application --app-replay-mode relaxed --set full --section MemoryWorkloadAnalysis_Tables -o ./cudaProgramOut

```


