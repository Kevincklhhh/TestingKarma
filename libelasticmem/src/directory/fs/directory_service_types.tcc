/**
 * Autogenerated by Thrift Compiler (0.11.0)
 *
 * DO NOT EDIT UNLESS YOU ARE SURE THAT YOU KNOW WHAT YOU ARE DOING
 *  @generated
 */
#ifndef directory_service_TYPES_TCC
#define directory_service_TYPES_TCC

#include "directory_service_types.h"

namespace elasticmem { namespace directory {

template <class Protocol_>
uint32_t rpc_replica_chain::read(Protocol_* iprot) {

  ::apache::thrift::protocol::TInputRecursionTracker tracker(*iprot);
  uint32_t xfer = 0;
  std::string fname;
  ::apache::thrift::protocol::TType ftype;
  int16_t fid;

  xfer += iprot->readStructBegin(fname);

  using ::apache::thrift::protocol::TProtocolException;

  bool isset_block_names = false;
  bool isset_slot_begin = false;
  bool isset_slot_end = false;

  while (true)
  {
    xfer += iprot->readFieldBegin(fname, ftype, fid);
    if (ftype == ::apache::thrift::protocol::T_STOP) {
      break;
    }
    switch (fid)
    {
      case 1:
        if (ftype == ::apache::thrift::protocol::T_LIST) {
          {
            this->block_names.clear();
            uint32_t _size0;
            ::apache::thrift::protocol::TType _etype3;
            xfer += iprot->readListBegin(_etype3, _size0);
            this->block_names.resize(_size0);
            uint32_t _i4;
            for (_i4 = 0; _i4 < _size0; ++_i4)
            {
              xfer += iprot->readString(this->block_names[_i4]);
            }
            xfer += iprot->readListEnd();
          }
          isset_block_names = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 2:
        if (ftype == ::apache::thrift::protocol::T_I32) {
          xfer += iprot->readI32(this->slot_begin);
          isset_slot_begin = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 3:
        if (ftype == ::apache::thrift::protocol::T_I32) {
          xfer += iprot->readI32(this->slot_end);
          isset_slot_end = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      default:
        xfer += iprot->skip(ftype);
        break;
    }
    xfer += iprot->readFieldEnd();
  }

  xfer += iprot->readStructEnd();

  if (!isset_block_names)
    throw TProtocolException(TProtocolException::INVALID_DATA);
  if (!isset_slot_begin)
    throw TProtocolException(TProtocolException::INVALID_DATA);
  if (!isset_slot_end)
    throw TProtocolException(TProtocolException::INVALID_DATA);
  return xfer;
}

template <class Protocol_>
uint32_t rpc_replica_chain::write(Protocol_* oprot) const {
  uint32_t xfer = 0;
  ::apache::thrift::protocol::TOutputRecursionTracker tracker(*oprot);
  xfer += oprot->writeStructBegin("rpc_replica_chain");

  xfer += oprot->writeFieldBegin("block_names", ::apache::thrift::protocol::T_LIST, 1);
  {
    xfer += oprot->writeListBegin(::apache::thrift::protocol::T_STRING, static_cast<uint32_t>(this->block_names.size()));
    std::vector<std::string> ::const_iterator _iter5;
    for (_iter5 = this->block_names.begin(); _iter5 != this->block_names.end(); ++_iter5)
    {
      xfer += oprot->writeString((*_iter5));
    }
    xfer += oprot->writeListEnd();
  }
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldBegin("slot_begin", ::apache::thrift::protocol::T_I32, 2);
  xfer += oprot->writeI32(this->slot_begin);
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldBegin("slot_end", ::apache::thrift::protocol::T_I32, 3);
  xfer += oprot->writeI32(this->slot_end);
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldStop();
  xfer += oprot->writeStructEnd();
  return xfer;
}

template <class Protocol_>
uint32_t rpc_file_status::read(Protocol_* iprot) {

  ::apache::thrift::protocol::TInputRecursionTracker tracker(*iprot);
  uint32_t xfer = 0;
  std::string fname;
  ::apache::thrift::protocol::TType ftype;
  int16_t fid;

  xfer += iprot->readStructBegin(fname);

  using ::apache::thrift::protocol::TProtocolException;

  bool isset_type = false;
  bool isset_permissions = false;
  bool isset_last_write_time = false;

  while (true)
  {
    xfer += iprot->readFieldBegin(fname, ftype, fid);
    if (ftype == ::apache::thrift::protocol::T_STOP) {
      break;
    }
    switch (fid)
    {
      case 1:
        if (ftype == ::apache::thrift::protocol::T_I32) {
          int32_t ecast8;
          xfer += iprot->readI32(ecast8);
          this->type = (rpc_file_type)ecast8;
          isset_type = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 2:
        if (ftype == ::apache::thrift::protocol::T_I32) {
          xfer += iprot->readI32(this->permissions);
          isset_permissions = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 3:
        if (ftype == ::apache::thrift::protocol::T_I64) {
          xfer += iprot->readI64(this->last_write_time);
          isset_last_write_time = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      default:
        xfer += iprot->skip(ftype);
        break;
    }
    xfer += iprot->readFieldEnd();
  }

  xfer += iprot->readStructEnd();

  if (!isset_type)
    throw TProtocolException(TProtocolException::INVALID_DATA);
  if (!isset_permissions)
    throw TProtocolException(TProtocolException::INVALID_DATA);
  if (!isset_last_write_time)
    throw TProtocolException(TProtocolException::INVALID_DATA);
  return xfer;
}

template <class Protocol_>
uint32_t rpc_file_status::write(Protocol_* oprot) const {
  uint32_t xfer = 0;
  ::apache::thrift::protocol::TOutputRecursionTracker tracker(*oprot);
  xfer += oprot->writeStructBegin("rpc_file_status");

  xfer += oprot->writeFieldBegin("type", ::apache::thrift::protocol::T_I32, 1);
  xfer += oprot->writeI32((int32_t)this->type);
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldBegin("permissions", ::apache::thrift::protocol::T_I32, 2);
  xfer += oprot->writeI32(this->permissions);
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldBegin("last_write_time", ::apache::thrift::protocol::T_I64, 3);
  xfer += oprot->writeI64(this->last_write_time);
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldStop();
  xfer += oprot->writeStructEnd();
  return xfer;
}

template <class Protocol_>
uint32_t rpc_data_status::read(Protocol_* iprot) {

  ::apache::thrift::protocol::TInputRecursionTracker tracker(*iprot);
  uint32_t xfer = 0;
  std::string fname;
  ::apache::thrift::protocol::TType ftype;
  int16_t fid;

  xfer += iprot->readStructBegin(fname);

  using ::apache::thrift::protocol::TProtocolException;

  bool isset_storage_mode = false;
  bool isset_persistent_store_prefix = false;
  bool isset_chain_length = false;
  bool isset_data_blocks = false;

  while (true)
  {
    xfer += iprot->readFieldBegin(fname, ftype, fid);
    if (ftype == ::apache::thrift::protocol::T_STOP) {
      break;
    }
    switch (fid)
    {
      case 1:
        if (ftype == ::apache::thrift::protocol::T_I32) {
          int32_t ecast11;
          xfer += iprot->readI32(ecast11);
          this->storage_mode = (rpc_storage_mode)ecast11;
          isset_storage_mode = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 2:
        if (ftype == ::apache::thrift::protocol::T_STRING) {
          xfer += iprot->readString(this->persistent_store_prefix);
          isset_persistent_store_prefix = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 3:
        if (ftype == ::apache::thrift::protocol::T_I32) {
          xfer += iprot->readI32(this->chain_length);
          isset_chain_length = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 4:
        if (ftype == ::apache::thrift::protocol::T_LIST) {
          {
            this->data_blocks.clear();
            uint32_t _size12;
            ::apache::thrift::protocol::TType _etype15;
            xfer += iprot->readListBegin(_etype15, _size12);
            this->data_blocks.resize(_size12);
            uint32_t _i16;
            for (_i16 = 0; _i16 < _size12; ++_i16)
            {
              xfer += this->data_blocks[_i16].read(iprot);
            }
            xfer += iprot->readListEnd();
          }
          isset_data_blocks = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      default:
        xfer += iprot->skip(ftype);
        break;
    }
    xfer += iprot->readFieldEnd();
  }

  xfer += iprot->readStructEnd();

  if (!isset_storage_mode)
    throw TProtocolException(TProtocolException::INVALID_DATA);
  if (!isset_persistent_store_prefix)
    throw TProtocolException(TProtocolException::INVALID_DATA);
  if (!isset_chain_length)
    throw TProtocolException(TProtocolException::INVALID_DATA);
  if (!isset_data_blocks)
    throw TProtocolException(TProtocolException::INVALID_DATA);
  return xfer;
}

template <class Protocol_>
uint32_t rpc_data_status::write(Protocol_* oprot) const {
  uint32_t xfer = 0;
  ::apache::thrift::protocol::TOutputRecursionTracker tracker(*oprot);
  xfer += oprot->writeStructBegin("rpc_data_status");

  xfer += oprot->writeFieldBegin("storage_mode", ::apache::thrift::protocol::T_I32, 1);
  xfer += oprot->writeI32((int32_t)this->storage_mode);
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldBegin("persistent_store_prefix", ::apache::thrift::protocol::T_STRING, 2);
  xfer += oprot->writeString(this->persistent_store_prefix);
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldBegin("chain_length", ::apache::thrift::protocol::T_I32, 3);
  xfer += oprot->writeI32(this->chain_length);
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldBegin("data_blocks", ::apache::thrift::protocol::T_LIST, 4);
  {
    xfer += oprot->writeListBegin(::apache::thrift::protocol::T_STRUCT, static_cast<uint32_t>(this->data_blocks.size()));
    std::vector<rpc_replica_chain> ::const_iterator _iter17;
    for (_iter17 = this->data_blocks.begin(); _iter17 != this->data_blocks.end(); ++_iter17)
    {
      xfer += (*_iter17).write(oprot);
    }
    xfer += oprot->writeListEnd();
  }
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldStop();
  xfer += oprot->writeStructEnd();
  return xfer;
}

template <class Protocol_>
uint32_t rpc_dir_entry::read(Protocol_* iprot) {

  ::apache::thrift::protocol::TInputRecursionTracker tracker(*iprot);
  uint32_t xfer = 0;
  std::string fname;
  ::apache::thrift::protocol::TType ftype;
  int16_t fid;

  xfer += iprot->readStructBegin(fname);

  using ::apache::thrift::protocol::TProtocolException;

  bool isset_name = false;
  bool isset_status = false;

  while (true)
  {
    xfer += iprot->readFieldBegin(fname, ftype, fid);
    if (ftype == ::apache::thrift::protocol::T_STOP) {
      break;
    }
    switch (fid)
    {
      case 1:
        if (ftype == ::apache::thrift::protocol::T_STRING) {
          xfer += iprot->readString(this->name);
          isset_name = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 2:
        if (ftype == ::apache::thrift::protocol::T_STRUCT) {
          xfer += this->status.read(iprot);
          isset_status = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      default:
        xfer += iprot->skip(ftype);
        break;
    }
    xfer += iprot->readFieldEnd();
  }

  xfer += iprot->readStructEnd();

  if (!isset_name)
    throw TProtocolException(TProtocolException::INVALID_DATA);
  if (!isset_status)
    throw TProtocolException(TProtocolException::INVALID_DATA);
  return xfer;
}

template <class Protocol_>
uint32_t rpc_dir_entry::write(Protocol_* oprot) const {
  uint32_t xfer = 0;
  ::apache::thrift::protocol::TOutputRecursionTracker tracker(*oprot);
  xfer += oprot->writeStructBegin("rpc_dir_entry");

  xfer += oprot->writeFieldBegin("name", ::apache::thrift::protocol::T_STRING, 1);
  xfer += oprot->writeString(this->name);
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldBegin("status", ::apache::thrift::protocol::T_STRUCT, 2);
  xfer += this->status.write(oprot);
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldStop();
  xfer += oprot->writeStructEnd();
  return xfer;
}

template <class Protocol_>
uint32_t directory_service_exception::read(Protocol_* iprot) {

  ::apache::thrift::protocol::TInputRecursionTracker tracker(*iprot);
  uint32_t xfer = 0;
  std::string fname;
  ::apache::thrift::protocol::TType ftype;
  int16_t fid;

  xfer += iprot->readStructBegin(fname);

  using ::apache::thrift::protocol::TProtocolException;

  bool isset_msg = false;

  while (true)
  {
    xfer += iprot->readFieldBegin(fname, ftype, fid);
    if (ftype == ::apache::thrift::protocol::T_STOP) {
      break;
    }
    switch (fid)
    {
      case 1:
        if (ftype == ::apache::thrift::protocol::T_STRING) {
          xfer += iprot->readString(this->msg);
          isset_msg = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      default:
        xfer += iprot->skip(ftype);
        break;
    }
    xfer += iprot->readFieldEnd();
  }

  xfer += iprot->readStructEnd();

  if (!isset_msg)
    throw TProtocolException(TProtocolException::INVALID_DATA);
  return xfer;
}

template <class Protocol_>
uint32_t directory_service_exception::write(Protocol_* oprot) const {
  uint32_t xfer = 0;
  ::apache::thrift::protocol::TOutputRecursionTracker tracker(*oprot);
  xfer += oprot->writeStructBegin("directory_service_exception");

  xfer += oprot->writeFieldBegin("msg", ::apache::thrift::protocol::T_STRING, 1);
  xfer += oprot->writeString(this->msg);
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldStop();
  xfer += oprot->writeStructEnd();
  return xfer;
}

}} // namespace

#endif
