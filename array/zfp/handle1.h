// const handle to a 1D array or view element; this class is nested within container_type
class const_handle {
public:
  typedef container_type::value_type value_type;

protected:
  // protected constructor
  explicit const_handle(container_type* container, uint i) : container(container), i(i) {}

  // derefence handle
  value_type get() const { return container->get(i); }

  container_type* container; // container
  uint i;                    // element index
};

// reference to a 1D array or view element; this class is nested within container_type
class handle : public const_handle {
protected:
  // protected constructor
  explicit handle(container_type* container, uint i) : const_handle(container, i) {}

  // assign value through handle
  void set(value_type val) { container->set(i, val); }

  using const_handle::container;
  using const_handle::i;
};
